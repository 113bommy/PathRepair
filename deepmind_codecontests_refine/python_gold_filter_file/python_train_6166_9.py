n,m=map(int,input().split(" "))
A=[]
front=""
end=""
mid=""
for i in range(n):
    s=input()
    A.append(s)
    r=s[::-1]
    if r in A and r!=s:
        front+=r
        end=s+end
    elif r==s:
        mid=s
fins=front+mid+end
print(len(fins))
print(fins)