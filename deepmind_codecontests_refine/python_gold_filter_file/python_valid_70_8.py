"""	Problem Statement
Polycarp has a string s. Polycarp performs the following actions until the string s is empty (t is initially an empty string):

he adds to the right to the string t the string s, i.e. he does t=t+s, where t+s is a concatenation of the strings t and s;
he selects an arbitrary letter of s and removes from s all its occurrences (the selected letter must occur in the string s at the moment of performing this action).
Polycarp performs this sequence of actions strictly in this order.

Note that after Polycarp finishes the actions, the string s will be empty and the string t will be equal to some value (that is undefined and depends on the order of removing).

E.g. consider s="abacaba" so the actions may be performed as follows:

t="abacaba", the letter 'b' is selected, then s="aacaa";
t="abacabaaacaa", the letter 'a' is selected, then s="c";
t="abacabaaacaac", the letter 'c' is selected, then s="" (the empty string).
You need to restore the initial value of the string s using only the final value of t and find the order of removing letters from s.
"""

class Solution:
	def restoreOriginal(self,word):
		alphabets = {}
		order_removed = []
		for i in range(len(word)-1,-1,-1):
			if word[i] not in alphabets:
				alphabets[word[i]] = 1
				order_removed.append(word[i])
			else:
				alphabets[word[i]] += 1

		order_removed.reverse()
		order_string = ""
		multiple_of_letters = 1

		for i in order_removed:
			if alphabets[i]%multiple_of_letters != 0:
				return [-1]
			else:
				alphabets[i] = alphabets[i]//multiple_of_letters
				order_string += i
			multiple_of_letters += 1
		
		ans = ""

		for i in word:
			if alphabets[i] == 0:
				break
			else:
				ans += i
				alphabets[i] -= 1

		create_word = ans
		psuedo_ans = ans

		for i in order_removed:
			t = ""
			for j in psuedo_ans:
				if i != j:
					t += j
			create_word += t
			psuedo_ans = t

		if create_word!=word:
			return [-1]
		else:
			return ans,order_string



if __name__ == "__main__":
	n = int(input())
	while n>0:
		word = input()
		obj = Solution()
		ans = obj.restoreOriginal(word)
		if len(ans) == 1:
			print(ans[0])
		else:
			print(ans[0],ans[1])
		n = n-1
else:
	pass

