n = int(input())
ls = [int(i) for i in input().split()]
print(max(ls)-min(ls), (ls.count(max(ls))*ls.count(min(ls)) if max(ls) != min(ls) else ls.count(max(ls))*(ls.count(max(ls))-1)//2))