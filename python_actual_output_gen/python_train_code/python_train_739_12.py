n=int(input())
b=0
for i in range(n+1,100000):
    if '8' in str(i):
        print(int(i)-n)
        break

        
