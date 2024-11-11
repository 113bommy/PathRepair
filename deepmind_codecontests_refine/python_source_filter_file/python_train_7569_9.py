n = int(input())
w = input()

div = [i for i in range(2,n//2+2) if n%i==0]+[n]
for i in range(len(div)):
    w = list(reversed(w[:div[i]]))+list(w[div[i]:])
    
print(''.join(w))
