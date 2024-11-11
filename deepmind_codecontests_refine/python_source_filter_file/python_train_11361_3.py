arr=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for _ in range(int(input())):
    a , b = map(int,input().split())
    ans = a//b;
    ar=arr[0:b]
    print(''.join(ar*ans),end="")
    ans=a%b
    ar=arr[0:ans]
    print(''.join(ar*ans))