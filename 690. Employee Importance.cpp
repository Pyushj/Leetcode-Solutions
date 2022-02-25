/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int src,vector<Employee*> employees, int& imp)
    {
        Employee* temp=nullptr;
        for(auto emp:employees)
        {
            if(emp->id ==src)
            {
                imp+=emp->importance;
                emp->importance=0;
                temp=emp;
                break;
            }
        }
        for(auto x: temp->subordinates)
        {
            dfs(x,employees,imp);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        int imp=0;
        for(auto x:employees)
        {
            if(x->id==id)
            {
                dfs(x->id,employees,imp);
                break;
            }
        }
        return imp;
    }
};
