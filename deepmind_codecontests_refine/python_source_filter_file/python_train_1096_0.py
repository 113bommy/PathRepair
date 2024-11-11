n = int(input())
a = list(map(int,input().split()))
mini = a.index(min(a))
maxi = a.index(max(a))
print(maxi,mini)
mid = n//2
print(mid)
if maxi > mini and maxi > mid and mini > mid:
    print("here 1")
    print(maxi)
elif maxi > mini and maxi > mid and mini == 0:
    print("here 1")
    print(n-1)
elif maxi > mini and maxi > mid and mini < mid:
    print(max(maxi,abs(mini-(n-1))))
elif mini > maxi and mini > mid and maxi <mid:
    print("here 2")
    print(max(mini,abs(maxi-(n-1))))
elif maxi > mini and maxi <= mid:
    print("here 3")
    print(abs(mini-(n-1)))
elif mini > maxi and mini <= mid:
    print("here 4")
    print(abs(maxi-(n-1)))
elif mini>maxi:
    print(mini)
elif maxi>mini:
    print(maxi)
else:
    print(1)