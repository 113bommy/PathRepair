n,a,b = map(int, input().split())

answer=[1]
if a==0 and b==0:
    print("1"*n)
    exit(0)
if n<= a+b or (b==0 and n<= a+1):
    print(-1)
    exit(0)

for i in range(b):
    answer.append(2**(i+1))
if b == 0: 
    answer.append(1)
for i in range(a):
    answer.append(answer[-1]+1)
z=len(answer)
for i in range(n-z):
    answer.append(answer[-1])
    
print(" ".join(str(el) for el in answer))