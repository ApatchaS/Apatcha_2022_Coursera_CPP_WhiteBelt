void MoveStrings (vector<string>& source, vector<string>& destination)
{
	for (auto a : source)
		destination.push_back(a);
	source.clear();
	return ;
}