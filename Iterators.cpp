// code_report
// https://youtu.be/yTi46Pb32qg

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>

template<typename T>
std::string get_iterator_type (T it) {

	if      (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::input_iterator_tag))	  return "Input";
	else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::output_iterator_tag))        return "Output";
	else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::forward_iterator_tag))       return "Forward";
	else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::bidirectional_iterator_tag)) return "Bidirectional";
	else if (typeid (std::iterator_traits<T>::iterator_category) == typeid (std::random_access_iterator_tag)) return "Random Access";

	return "missing";
}

int main () {

	std::array<int,1> a;
	std::vector<int> v;
	std::deque<int> d;
	std::forward_list<int> fl;
	std::list<int> l;

	std::set<int> s;
	std::map<int, int> m;
	
	std::unordered_map<int, int> um;
	std::unordered_set<int, int> us;

	auto it  = a.begin  ();
	auto it1 = v.begin  ();
	auto it2 = d.begin  ();
	auto it3 = fl.begin ();
	auto it4 = l.begin  ();

	auto it5 = s.begin  ();
	auto it6 = m.begin  ();

	auto it7 = us.begin ();
	auto it8 = um.begin ();

	std::cout << "\nSequence Containers:\n\n";
	std::cout << "array::begin         () returns a " << get_iterator_type (it)  << " Iterator.\n";
	std::cout << "vector::begin        () returns a " << get_iterator_type (it1) << " Iterator.\n";
	std::cout << "deque::begin         () returns a " << get_iterator_type (it2) << " Iterator.\n";
	std::cout << "forward_list::begin  () returns a " << get_iterator_type (it3) << " Iterator.\n";

	std::cout << "\nAssociative Containers:\n\n";
	std::cout << "set::begin           () returns a " << get_iterator_type (it5) << " Iterator.\n";
	std::cout << "map::begin           () returns a " << get_iterator_type (it6) << " Iterator.\n";

	std::cout << "\nUnordered Associative Containers:\n\n";
	std::cout << "unordered_map::begin () returns a " << get_iterator_type (it7) << " Iterator.\n";
	std::cout << "unordered_set::begin () returns a " << get_iterator_type (it8) << " Iterator.\n";

	return 0;
}
