N=int(input())
A=list(map(int,input().split()))
even=sorted([a for a in A if a%2==0])
odd=sorted([a for a in A if a%2==1])
even_len = len(even)
odd_len = len(odd)
if even_len > odd_len + 1:
    print(sum(even[:even_len-odd_len-1]))
elif odd_len > even_len + 1:
    print(sum(even[:odd_len-even_len-1]))
else:
    print(0)
