n=input()
if '4' not in n and '7' not in n:
    print(-1)
elif(n.count('4')==n.count('7')):
    print(4)

elif(n.count('4')<n.count('7')):
    print(7)

else:
    print(4)
