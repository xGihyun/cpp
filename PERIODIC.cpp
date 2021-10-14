#include <iostream>

using namespace std;

int main() {
    double water, elec, food, net, child, pet, debt, misc, total; //THIS MONTH
    double lwater, lelec, lfood, lnet, lchild, lpet, ldebt, lmisc, ltotal; //LAST MONTH
    double ftotal; //FINAL TOTAL (DIFFERENCE)
    
    //DRAW DIVIDER
    for(int i = 0; i < 80; i++){
        cout<<"-";
    }
    
    //COMPUTATION
    cout<<"\n\n";
    
    cin>>water>>elec>>food>>net>>child>>pet>>debt>>misc;
    
        cout<<"Expenses this month:"<<"\n\n";
        
        cout<<"Water           = "<<water<<"\n";
        cout<<"Electricity     = "<<elec<<"\n";
        cout<<"Food            = "<<food<<"\n";
        cout<<"Internet        = "<<net<<"\n";
        cout<<"Child care      = "<<child<<"\n";
        cout<<"Pet care        = "<<pet<<"\n";
        cout<<"Debt            = "<<debt<<"\n";
        cout<<"Miscellaneous   = "<<misc<<"\n\n";
        
        total = (water+elec+food+net);
        cout<<"Total expenses  = "<<total<<"\n\n";
        
        for(int i = 0; i < 80; i++){
            cout<<"-";
        }
        cout<<"\n\n";
        
        cin>>lwater>>lelec>>lfood>>lnet>>lchild>>lpet>>ldebt>>lmisc;
        
        cout<<"Expenses last month:"<<"\n\n";
        
        cout<<"Water           = "<<lwater<<"\n";
        cout<<"Electricity     = "<<lelec<<"\n";
        cout<<"Food            = "<<lfood<<"\n";
        cout<<"Internet        = "<<lnet<<"\n";
        cout<<"Child care      = "<<lchild<<"\n";
        cout<<"Pet care        = "<<lpet<<"\n";
        cout<<"Debt            = "<<ldebt<<"\n";
        cout<<"Miscellaneous   = "<<lmisc<<"\n\n";
        
        ltotal = (lwater+lelec+lfood+lnet);
        cout<<"Total expenses  = "<<ltotal<<"\n\n";
        
        for(int i = 0; i < 80; i++){
            cout<<"-"; //DRAW DIVIDER
        }
        cout<<"\n\n";
        
        ftotal = (total-ltotal);
        
        cout<<total<<" - "<<ltotal<<" = "<<ftotal<<"\n\n";
        
        cout<<"The difference between the expenses this month and last month is = "<<ftotal<<"\n\n";
        
        for(int i = 0; i < 80; i++){
            cout<<"-"; //DRAW DIVIDER
        }
        cout<<"\n\n";
        
        if(ftotal < 0)
        {
            cout<<"Our family was able to save "<<(ftotal * -1)<<" pesos."<<"\n\n"<<"GOOD JOB!"<<"\n\n";
        }
        else if(ftotal == 0)
        {
            cout<<"Our family spent "<<ftotal<<" pesos"<<"\n\n"<<"THE TOTAL MONEY SPENT ON BOTH MONTHS WERE EQUAL!"<<"\n\n";
        }
        else{
            cout<<"Our family over spent for "<<ftotal<<" pesos."<<"\n\n"<<"SAVE MORE NEXT TIME!"<<"\n\n";
        }
        
        for(int i = 0; i < 80; i++){
            cout<<"-"; //DRAW DIVIDER
        }
}
    
