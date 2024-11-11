while True:
	try:
		
		def solution(k, a, t):
			#two pointer
			n = len(a)
			l = r = mx = s = 0
			while r < n:
				while r < k:
					if t[r] == 0:
						s += a[r]
						mx = max(mx, s)
					r += 1
				if r ==n:break
				if t[r] == 0:
					s += a[r]
				if t[l] == 0:
					s -= a[l]
				mx = max(mx, s)
				l += 1;r += 1
			
			ts = 0
			for i in range(n):
				if t[i]:
					ts += a[i]
			print(ts+mx)
				
				
				
					
				
		"""def solution(k, a, t):
			n = len(a)
			i =s =  0
			for x in t:
				if x:
					s += a[i]
				i += 1
			i = mx = 0
			while i <= n -k:
				ts = 0
				if i == n- k:
					for j in range(i, n, 1):
						if t[j] == 0:
							ts += a[j]
					mx = max(ts, mx)
				elif t[i] == 0:
					for j in range(i, i+k, 1):
						if t[j] == 0:
							ts += a[j]
					mx = max(ts, mx)
				i += 1
			print(s+mx)"""
			
		
		def read():
			n, k = map(int, input().split())
			a = list(map(int, input().split()))
			t = list(map(int, input().split()))
			solution(k, a, t)
		if __name__ == "__main__":
			read()
	except EOFError:
		break