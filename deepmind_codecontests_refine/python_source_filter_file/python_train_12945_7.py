inStr = input()
largest = max(inStr)
c = inStr.count(largest)
c -= c%2
print(c*largest)