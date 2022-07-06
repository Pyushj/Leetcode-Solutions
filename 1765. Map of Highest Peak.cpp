#define Pair pair<int,int>
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,-2));
        queue<Pair> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int height=-1;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int size=q.size();
            height++;
            while(size--)
            {
                Pair temp=q.front();
                q.pop();
                res[temp.first][temp.second]=height;
                for(int i=0;i<4;i++)
                {
                     int r=temp.first + dir[i][0];
                     int c=temp.second + dir[i][1];
                    if(r>=0 && r< m && c>=0 && c<n && res[r][c]==-2)
                    {
                        q.push({r,c});
                        res[r][c]=0;
                    }
                }
            }
        }
        return res;
        
        
        
    }
};











// import { MessageTypes, TYPED_MESSAGE_SCHEMA} from "@metamask/eth-sig-util";
const { SignTypedDataVersion } = require("@metamask/eth-sig-util");
let et=require("@metamask/eth-sig-util");
const { toBuffer, ecsign } = require("ethereumjs-util");
const ethUtil = require('ethereumjs-util');

const json={
  "types": {
    "EIP712Domain": [
      {"name": "name", "type": "string"},
      {"name": "version", "type": "string"},
      {"name": "chainId", "type": "uint256"},
      {"name": "verifyingContract", "type": "address"}
    ],
    "Person": [
      {"name": "name", "type": "string"},
      {"name": "wallet", "type": "address"}
    ],
    "Mail": [
      {"name": "from", "type": "Person"},
      {"name": "to", "type": "Person"},
      {"name": "contents", "type": "string"}
    ]
  },
  "primaryType": "Mail",
  "domain": {
    "name": "Ether Mail",
    "version": "1",
    "chainId": 1,
    "verifyingContract": "0xCcCCccccCCCCcCCCCCCcCcCccCcCCCcCcccccccC"
  },
  "message": {
    "from": {
      "name": "Cow",
      "wallet": "0xCD2a3d9F938E13CD947Ec05AbC7FE734Df8DD826"
    },
    "to": {
      "name": "Bob",
      "wallet": "0xbf4fA4D0EC497Dc679469cC2511Ccfae076aBD68"
    },
    "contents": "Hello, Bob how are you!"
  }
};

// hashing typedData
let x=et.TypedDataUtils.eip712Hash(json,SignTypedDataVersion.V4);
//console.log(ethUtil.bufferToHex(x));


//signing typedData
let key=Buffer.from('dd762d325ad71e8eac759b2dd938113a4ec84eb89d43eeee17a67a84ff8f4b50','hex');
let signatr=et.signTypedData({privateKey:key,data:json,version:SignTypedDataVersion.V4});
//console.log(signatr);

// const sig=ecsign(x,key);
// console.log(ethUtil.bufferToHex(toBuffer(sig.v)));
// console.log(ethUtil.bufferToHex(sig.r));
// console.log(ethUtil.bufferToHex(sig.s));


//recovering Address
let sg="0x2bf73a54d92e57f7765934d3633a32b6f4cbe23832f2ad1565cee10dfb073f432fd899fab641ec7dc72a8357bd061596bd5cf37832e48e8a11fd6899cc23cf1a1c";
let add=et.recoverTypedSignature({data:json,signature:sg,version:SignTypedDataVersion.V4});
console.log(add);





