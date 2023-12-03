#pragma once
class _32BitData
{
	//����32λ���������͵ĸ���
public :
	int sub;
	unsigned int data;
};

class MK : public _32BitData
{
	//128bit�ķ�Ϊ32bit��Կ �ܹ��ĸ�
public:
	void setMK(int num, unsigned int cont)
	{
		sub = num;
		data = cont;
	}
private:
};

class FK : public _32BitData
{
	//ϵͳ���� ÿһ���ʾ32λ����
public:
	void setFK(int num, unsigned int cont)
	{
		sub = num;
		data = cont;
	}
private:
};

class CK : public _32BitData
{
	//�̶����� ������Կ��չ�㷨 ÿһ�Ϊ32λ����
public:
	void setCK(int num, unsigned int cont) {
		sub = num;
		data = cont;
	}
private:
};

class rk : public _32BitData
{
	//����Կ ÿһ�Ϊ32λ���� �ɼ�����Կͨ����Կ��չ�㷨����
public:
	void setrk(int num, unsigned int cont){
		sub = num;
		data = cont;
	}
	void generateKi(MK MKi, FK FKi) {
		data = MKi.data xor FKi.data;
	}
private:
};

class TData : public _32BitData
{
public:
	unsigned char AData[4];
	unsigned char BData[4];
	void generateA(rk Ks[4], CK CKi) {
		data = Ks[1].data xor Ks[2].data xor Ks[3].data xor CKi.data;
		for (int i = 0; i < 4; ++i) 
			AData[i] = (data >> (-8 * i + 24)) & 0xff;
	}
private:
};
