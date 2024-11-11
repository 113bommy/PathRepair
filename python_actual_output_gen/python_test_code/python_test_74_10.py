x=[int(input()) for i in range(5)]
print("Yay!" if max(x)-min(x)>=k else ":(")