import bisect
n,m=list(map(int,input().strip().split()))
s=input().strip()
t=input().strip()
print(s)
x=s.find('*')
if(len(s)>len(t)+1):
    print("NO")
else:
    if(x==0):
        if(s[1:]==t[len(t)-len(s)+1:len(t)]):
            print("YES")
        else:
            print("NO")
    elif(x==len(s)-1):
        if(s[:len(s)-1]==t[0:len(s)-1]):
            print("YES")
        else:
            print("NO")
    else:
    
        if((s[:x]==t[0:x]) and (s[x+1:]==t[len(t)+x-len(s)+1:len(t)])):
            print("YES")
        else:
            print("NO")
# print(x)

    
    
    
    
    
    