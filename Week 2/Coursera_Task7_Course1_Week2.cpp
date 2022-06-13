vector <int> Reversed(const vector<int>& v)
{
	vector<int> vr;
	for (int i = v.size() - 1; i >= 0; --i)
		vr.push_back(v[i]);
	return (vr);
}
