A,B = map(int, input().split())
ans=-1
for n in range(101):
    if int(n*0.08)==A and int(n*0.1)==B:
        ans=n
        break
print(ans)