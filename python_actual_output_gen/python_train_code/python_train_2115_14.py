a,b,c,d = map(int, input().split())
l=a+b
r=c+d
printT("Left" if l>r else "Balanced" if l==r else "Right")