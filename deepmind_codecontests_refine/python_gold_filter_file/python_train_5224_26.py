



def hotel(n,s,x):

    for i in range(n):
        if s[i]== 'L':
            
            leftd(x);
        elif s[i] == 'R':
            
            rightd(x);
        else:
            q = s[i];
            q = int(q);
            x[q]=0;
            
def leftd(x):
    for j in range(10):
        
        if x[j]==0:
            x[j]=1;
        
            
            break;
            
def rightd(x):
    k = 9;
    
    while k>=0:
        if x[k]==0:
            x[k]=1;
            break;
        k = k-1;
    
        
        
n = input();
n = int(n);
s = input();
x = [];
for i in range(10):
    x.append(0);
hotel(n,s,x);
for t in x:

    print(t,end ="");
        
    
        
        