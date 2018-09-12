# Longest palindromic subsequence in a given string
# Example= CHARACTER - CARAC

s = 'AAABABBB'

def lps(i,j):
	# print(i,j)
	if( i <= j):
		if( i == j):
			return s[i]
		elif( s[i] == s[j] ):
			return s[i] + lps(i+1, j-1) + s[i]
		else:
			a = lps(i+1,j)
			b = lps(i,j-1)
			if(len(a) > len(b)):
				return a
			else:
				return b
	else:	
		return "";

st = set()
for i in range(0, len(s)):
	for j in range(0,i):
		st.add(lps(j,i))

maxlen = 0
for i in st:
	if(len(i) > maxlen):
		maxlen = len(i)

for i in st:
	if(len(i) == maxlen):
		print i