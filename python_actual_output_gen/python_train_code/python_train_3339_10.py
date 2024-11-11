n=int(input())
s=set()
for i in range(n):
    s=s^set(input())
print(len(s))