
n = int(input())
a = [ int(x[-1])%2 for x in input().split()]

def rule(s1,s2):
    if(s1==s2):
        return 'T'
    else: return False    

i=0
series = a[0]
series_len=0
res=[]
prev=''
while(i<=n):
    if(i<n and a[i]==series):
        series_len+=1        
    else:
        if(series_len%2!=0):
            if(series==0):
                if(prev=='F0'):
                    res.pop(-1)
                    if(len(res)>=1):
                        prev=res[-1]
                    else:
                        prev=''
                else:
                    res.append('F0')
                    prev='F0'
            else:
                if(prev=='F1'):
                    res.pop(-1) 
                    if(len(res)>=1):
                        prev=res[-1]
                    else:
                        prev=''
                else:
                    res.append('F1')
                    prev='F1'
        if(i<n):
            series= a[i]
            series_len=1
        
    i+=1

#print(res)        
if(len(res)==1):
    
    print('Yes')
else:
    print('No')
        
        
        
    
    
 
    
    
    