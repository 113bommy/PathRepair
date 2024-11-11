h1, a1, c1 = map(int, input().split())
h2, a2 = map(int, input().split())
ans = []
while(h2>0):
    if(h1<=a2 and h2 >=a1):
        ans.append('HEAL')
        h1+=c1
    else:
        h2-=a1
        ans.append('STRIKE')
    h1-=a2
print(len(ans), *ans, sep='\n')