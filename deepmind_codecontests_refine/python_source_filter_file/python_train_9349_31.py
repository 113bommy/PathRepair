K, A, B = [int(i) for i in input().split()]
if K + 1 >= A and A + 2 <=B:
    print(((K+1)-A)//2*(B-A) - A + ((K+1)-A)%2)
else:
    print(K+1)