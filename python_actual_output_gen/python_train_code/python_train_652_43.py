n=input()
print("Bad" if any(n[i]==n[i-1] for i in range(1,3)) else "Good")
