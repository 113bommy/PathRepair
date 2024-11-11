n = input()
print("No" if ((n//10) % 111 and (n%1000) % 111) else "Yes")