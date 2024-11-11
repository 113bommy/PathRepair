R = lambda: map(int,input().split())
n,m = R()
l = []
top=-1
for i in range(n):
        l1 = input()
        l.insert(0,l1)
        if top is -1 and l[0].find('1') is not -1:
            top=n-i-1
left,right = 0,m+1

for i in range(top):
        if '1' in l[i]:
            left,right= min(left+2*l[i].rfind('1')+1, right+m+2), min(left+m+2, right+2*(m+1-l[i].find('1'))+1)
        else:
            left,right = left+1, right+1
print(min(left+l[top].rfind('1'), right+(m+1-l[top].find('1'))))