n=int(input())
answer='NO'
for i in range(n):
    s,before,after=input().split()
    before,after=int(before),int(after)
    if before>2400 and after-before>0:
        answer='YES'
print(answer)
