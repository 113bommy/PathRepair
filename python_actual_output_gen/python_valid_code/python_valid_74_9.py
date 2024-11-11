n=int(input())
ans=""
if n==0:print("0");exit()
while n!=0:
    ans +=str(n%2)
    n=n//(-2)
print("".join(ans[::-1]))