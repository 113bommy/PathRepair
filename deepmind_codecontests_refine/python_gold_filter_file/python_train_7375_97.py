N = int(input())
an = list(map(int, input().split()))
an.sort(reverse=True)
print(sum(an[1::2][:N]))
