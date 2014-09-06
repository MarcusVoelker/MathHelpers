#pragma once

std::pair<int64_t, int64_t> eea(int64_t a, int64_t b)
{
	int64_t x = 0;
	int64_t y = 1;
	int64_t u = 1;
	int64_t v = 0;
	while (a != 0)
	{
		int64_t q = b / a;
		int64_t r = b % a;
		int64_t m = x - u*q;
		int64_t n = y - v*q;
		b = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}
	return std::make_pair(x, y);
}

int64_t inverse(int64_t x, int64_t m)
{
	return eea(x, m).first;
}

template <int64_t M>
struct ModInt
{
	int64_t val;

	ModInt& operator+=(int64_t other)
	{
		val = (val + other) % M;
		return *this;
	}

	ModInt& operator-=(int64_t other)
	{
		val = (val - other) % M;
		return *this;
	}

	ModInt& operator*=(int64_t other)
	{
		val = (val * other) % M;
		return *this;
	}

	ModInt& operator/=(int64_t other)
	{
		val = (val * inverse(other, M)) % M;
		return *this;
	}

	ModInt& operator^=(int64_t other)
	{
		int i = 0;
		int64_t temp = val;
		int64_t res = 1;
		while (other != 0)
		{
			if (other & 1)
				res = (temp * res) % M;
			other >>= 1;
			temp = (temp*temp) % M;
			i++;
		}
		val = res;
		return *this;
	}

	ModInt& operator+=(ModInt const& other) { return *this += other.val; }
	ModInt& operator-=(ModInt const& other) { return *this -= other.val; }
	ModInt& operator*=(ModInt const& other) { return *this *= other.val; }
	ModInt& operator/=(ModInt const& other) { return *this /= other.val; }
	ModInt& operator^=(ModInt const& other) { return *this ^= other.val; }

	ModInt operator+(int64_t const &rhs) const
	{
		ModInt res = *this;
		return res += rhs;
	}

	ModInt operator-(int64_t const &rhs) const
	{
		ModInt res = *this;
		return res -= rhs;
	}

	ModInt operator*(int64_t const &rhs) const
	{
		ModInt res = *this;
		return res *= rhs;
	}

	ModInt operator/(int64_t const &rhs) const
	{
		ModInt res = *this;
		return res /= rhs;
	}

	ModInt operator^(int64_t const &rhs) const
	{
		ModInt res = *this;
		return res ^= rhs;
	}

	ModInt operator+(ModInt const &rhs) const
	{
		ModInt res = *this;
		return res += rhs;
	}

	ModInt operator-(ModInt const &rhs) const
	{
		ModInt res = *this;
		return res -= rhs;
	}

	ModInt operator*(ModInt const &rhs) const
	{
		ModInt res = *this;
		return res *= rhs;
	}

	ModInt operator/(ModInt const &rhs) const
	{
		ModInt res = *this;
		return res /= rhs;
	}

	ModInt operator^(ModInt const &rhs) const
	{
		ModInt res = *this;
		return res ^= rhs;
	}

	ModInt operator+() const
	{
		ModInt res = *this;
		return res;
	}

	ModInt operator-() const
	{
		ModInt res = *this;
		return res * (-1);
	}

	ModInt& operator++() { return *this += 1; }
	ModInt& operator--() { return *this -= 1; }

	ModInt operator++(int _)
	{
		ModInt res = *this;
		++*this;
		return res;
	}

	ModInt operator--(int _)
	{
		ModInt res = *this;
		--*this;
		return res;
	}

	bool operator==(ModInt const& rhs) const { return val == rhs.val; }
	bool operator!=(ModInt const& rhs) const { return !(*this == rhs); }
	bool operator<(ModInt const& rhs) const { return val < rhs.val; }
	bool operator<=(ModInt const& rhs) const { return *this < rhs || *this == rhs; }
	bool operator>=(ModInt const& rhs) const { return !(*this < rhs); }
	bool operator>(ModInt const& rhs) const { return !(*this <= rhs); }

	bool operator==(int64_t rhs) const { return val == rhs; }
	bool operator!=(int64_t rhs) const { return !(*this == rhs); }
	bool operator<(int64_t rhs) const { return val < rhs; }
	bool operator<=(int64_t rhs) const { return *this < rhs || *this == rhs; }
	bool operator>=(int64_t rhs) const { return !(*this < rhs); }
	bool operator>(int64_t rhs) const { return !(*this <= rhs); }
};

template<int64_t M>
ModInt<M> operator+(int64_t lhs, ModInt<M> const& rhs) { return ModInt < M > { lhs } +rhs; }
template<int64_t M>
ModInt<M> operator-(int64_t lhs, ModInt<M> const& rhs) { return ModInt < M > { lhs } -rhs; }
template<int64_t M>
ModInt<M> operator*(int64_t lhs, ModInt<M> const& rhs) { return ModInt < M > { lhs } *rhs; }
template<int64_t M>
ModInt<M> operator/(int64_t lhs, ModInt<M> const& rhs) { return ModInt < M > { lhs } / rhs; }
template<int64_t M>
ModInt<M> operator%(int64_t lhs, ModInt<M> const& rhs) { return ModInt < M > { lhs } % rhs; }
