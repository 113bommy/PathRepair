for i in range (int(input())):
    r,b,k=map(int,input().split())
    if (r>b+k or b>r+k or k>r+b):
        print ("No")
    else:
        print("yes")