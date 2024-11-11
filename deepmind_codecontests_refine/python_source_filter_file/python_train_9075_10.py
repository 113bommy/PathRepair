a=input()
if "7" not in a or "4" not in a:exit(print(-1))
print([7,4][a.count("4")>=a.count("7")])
