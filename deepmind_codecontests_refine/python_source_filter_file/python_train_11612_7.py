#!/usr/bin/python3

class StdReader:
	def read_int(self):
		return int(self.read_string())

	def read_ints(self, sep=None):
		return [int(i) for i in self.read_strings(sep)]

	def read_float(self):
		return float(self.read_string())

	def read_floats(self, sep=None):
		return [float(i) for i in self.read_strings(sep)]

	def read_string(self):
		return input()

	def read_strings(self, sep=None):
		return self.read_string().split(sep)

reader = StdReader()


def main():
	h1, h2 = reader.read_ints()
	a, b = reader.read_ints()

	if h1 + a * (22-14) >= h2:
		print(0)
		return

	if a <= b:
		print(-1)
		return

	h1 = h1 + a*(22-14)
	dh = (a-b) * 12
	print(h1, h2, dh)

	days = (h2-h1) // dh + ((h2-h1)%dh != 0)

	print(days)


if __name__ == '__main__':
	main()
