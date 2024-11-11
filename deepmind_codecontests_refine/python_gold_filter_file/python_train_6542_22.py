N, P = map(int, input().split())
a_list = list(map(int, input().split()))
a=[i%2 for i in a_list]
if sum(a)>0:print(2**(N-1))
else:
    if P==0:
        print(2**N)
    else:
        print(0)