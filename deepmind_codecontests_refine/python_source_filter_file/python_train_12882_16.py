n = int(input())
arr = input().split(" ")
print (len(set([a for a in arr if a != 0])))
