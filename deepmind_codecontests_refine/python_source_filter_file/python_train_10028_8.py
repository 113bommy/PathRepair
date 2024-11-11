for _ in [0]*int(input()):
    s=int(input())
    if s==1:
        print(1)
        continue
    for i in range(1,s//2+1):
        if i*i==s:
            print(i)
            break
        elif i*i>s:
            print(i)
            break
