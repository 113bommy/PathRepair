s=input()
left="".join(reversed(s[0:s.index("^")]))
right=s[s.index("^")+1:]
sum1,sum2=0,0
for i in range(len(left)):
    if left[i] in "123456789":sum1+=int(left[i])*(i+1)
for i in range(len(right)):
    if right[i] in "123456789":sum2+=int(right[i])*(i+1)
print("right" if sum2>sum1 else("left" if sum2<sum1 else "balance"))