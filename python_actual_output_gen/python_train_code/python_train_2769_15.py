n=int(input())
L=input().split()
L=[int(i) for i in L]
print(L)
L.sort(reverse=True)
s=0
for i in range(1,len(L)):
    s=s+(int(L[i])*int((n-i+1)))
s=s+int(int(n)*int(L[0]))
print(s)
    
        
