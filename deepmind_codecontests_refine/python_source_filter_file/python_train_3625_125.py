import re
print("WA" if re.match("A[a-z]+C[a-z]+", input()) is None else "AC")