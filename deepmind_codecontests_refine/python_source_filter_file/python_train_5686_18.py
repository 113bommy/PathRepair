# import os
import sys
# from io import BytesIO, IOBase

# _str = str
# str = lambda x=b"": x if type(x) is bytes else _str(x).encode()

# BUFSIZE = 8192


# class FastIO(IOBase):
#     newlines = 0

#     def __init__(self, file):
#         self._fd = file.fileno()
#         self.buffer = BytesIO()
#         self.writable = "x" in file.mode or "r" not in file.mode
#         self.write = self.buffer.write if self.writable else None

#     def read(self):
#         while True:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             if not b:
#                 break
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines = 0
#         return self.buffer.read()

#     def readline(self):
#         while self.newlines == 0:
#             b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
#             self.newlines = b.count(b"\n") + (not b)
#             ptr = self.buffer.tell()
#             self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
#         self.newlines -= 1
#         return self.buffer.readline()

#     def flush(self):
#         if self.writable:
#             os.write(self._fd, self.buffer.getvalue())
#             self.buffer.truncate(0), self.buffer.seek(0)


# class IOWrapper(IOBase):
#     def __init__(self, file):
#         self.buffer = FastIO(file)
#         self.flush = self.buffer.flush
#         self.writable = self.buffer.writable
#         self.write = lambda s: self.buffer.write(s.encode("ascii"))
#         self.read = lambda: self.buffer.read().decode("ascii")
#         self.readline = lambda: self.buffer.readline().decode("ascii")


input = lambda: sys.stdin.readline().rstrip("\r\n")

import time
start = time.time()

from collections import deque
shows = []
for i in range(int(input())):
    shows.append([int(i) for i in input().split()])
shows.sort()
shows = deque(shows)
workers = [0, 0]
enough_tvs = True

while shows and enough_tvs:
    show = shows.popleft()
    if workers[0] < show[0]:
        workers[0] = show[1] 
        if workers[1] < show[0]:
            workers[1] = 0
    elif workers[1] < show[0]:
        workers[1] = show[1]
    else:
        enough_tvs = False

if enough_tvs:
    print("YES")
else:
    print("NO")

# print(time.time()-start)


# with open('input.txt', 'w') as file:
# 	for i in range(100000):
# 		file.writelines(f'{i} {i+1}\n')









# from collections import defaultdict
# def main():
# 	conflict_found = False
# 	times = defaultdict(int)
# 	for _ in range(int(input())):
# 		if conflict_found:
# 			break
# 		a, b = map(int, input().split())
# 		if not conflict_found:
# 			for j in range(a, b + 1):
# 				times[j] += 1
# 				if times[j] > 2:
# 					conflict_found = True
# 					break
# 	if conflict_found:
# 		return 'NO'
# 	else:
# 		return 'YES'	
# print(main())

