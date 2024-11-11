x=int(input())
n=input()
a=list(n)
ans=""
d={0:"",1:"",2:"2",3:"3",4:"223",5:"5",6:"532",7:"7",8:"7222",9:"722233"}
for e in n:
        e=int(e)
        ans=ans+d[e]
ans=sorted(ans,reverse=True)
print("".join(ans))
                
