#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP


namespace ft
{
	template<bool B, class T = void> struct enable_if;
	template<class T> struct enable_if<true, T> {typedef T type;};


	template<class T> struct remove_const			{typedef T type;};
	template<class T> struct remove_const<const T>	{typedef T type;};

	struct true_type
	{
		static const bool stat = true;
	};
	struct false_type
	{
		static const bool stat = false;
	};

	template <typename> struct is_base : public false_type{};
	template<> struct is_base<bool>: public true_type {};
	template<> struct is_base<char>: public true_type {};
	template<> struct is_base<signed char>: public true_type {};
	template<> struct is_base<unsigned char>: public true_type {};
	template<> struct is_base<wchar_t>: public true_type {};
	template<> struct is_base<char16_t>: public true_type {};
	template<> struct is_base<char32_t>: public true_type {};
	template<> struct is_base<short>: public true_type {};
	template<> struct is_base<unsigned short>: public true_type {};
	template<> struct is_base<int>: public true_type {};
	template<> struct is_base<unsigned int>: public true_type {};
	template<> struct is_base<long>: public true_type {};
	template<> struct is_base<unsigned long>: public true_type {};
	template<> struct is_base<long long>: public true_type {};
	template<> struct is_base<unsigned long long>: public true_type {};
	template<> struct is_base<__int128_t>: public true_type {};
	template<> struct is_base<__uint128_t>: public true_type {};

	template <class T>struct is_integral : public is_base<typename remove_const<T>::type> {};
}
#endif
