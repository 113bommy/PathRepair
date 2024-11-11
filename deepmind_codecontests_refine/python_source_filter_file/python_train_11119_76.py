x=[int(input()) for i in range(5)]
k=int(input())
print("Yay!" if max(x)-min(x)<k else ":(")