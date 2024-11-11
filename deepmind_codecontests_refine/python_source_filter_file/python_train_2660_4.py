a,b,c,d = sorted(map(int,input().split()))

if a+b>c or b+c>d:

    print("TRIANGLE")
elif a+b==c or b+c==d:

    print("SEGEMENT")

else:

    print("IMPOSSIBLE")