# 正規表現を利用する。

import re
if re.match("[A-Z]*?C[A-Z]*?F[A-Z]*?", input()):
	print("Yes")
else:
	print("No")
