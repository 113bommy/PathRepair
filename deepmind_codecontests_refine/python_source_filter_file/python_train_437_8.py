n=int(input());o=[]
for i in range(n):
    m=int(input())    
    o+=str(len(set(input().split())))
print('\n'.join(o))