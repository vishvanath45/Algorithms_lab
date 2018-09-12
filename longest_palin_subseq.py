# Longest palindromic subsequence in a given string
# Example= CHARACTER - CARAC

s = 'BABASBC'

ans1 = []
ans2 = ""

def lps(i,j):
	# print(i,j)
	if( i <= j):
		if( i == j):
			return s[i]
		elif( s[i] == s[j] ):
			return s[i] + lps(i+1, j-1) + s[i]
		else:
			if(len(lps(i+1,j)) > len(lps(i,j-1))):
				return lps(i+1,j)
			else:
				return lps(i,j-1)
	else:	
		return 0;

ans4 = lps(0,len(s)-1)

print "ans is ", ans4