#pragma once
struct SquareData
{
	char ObjectName[256]            = "nullptr";//�I�u�W�F�N�g�̖��O
	char Tag[256]                   = "nullptr";//�I�u�W�F�N�g�̃^�O
	float UpperLeftVertexX          = 0.0f;//��`�̍���X
	float UpperLeftVertexY          = 0.0f;//��`�̍���Y
	float LowerRightVertexX         = 0.0f;//��`�̉E��X
	float LowerRightVertexY         = 0.0f;//��`�̉E��Y
	float Wide                      = 0.0f;
	float Height                    = 0.0f;
};
struct CircleData
{
	char ObjectName[256] = "nullptr";//�I�u�W�F�N�g�̖��O
	char Tag[256]        = "nullptr";//�I�u�W�F�N�g�̃^�O
	float CenterX        = 0.0f;// �~�̒��S��X���W
	float CenterY        = 0.0f;// �~�̒��S��Y���W
	float Radius         = 0.0f;// �~�̔��a
};
enum class CollisionType
{
	NON    = 0,
	SQUARE = 1,
	CIRCLE = 2,
};
enum class SquareDirection
{
	NON   = 0,
	UP    = 1,
	RIGHT = 2,
	DOWN  = 3,
	LEFT  = 4
};
class Collision2D : public IGameObject
{
public:
	//�����蔻��̐���
	void SquareDataSet(float  Wide , float Height , float PositionX , float PositionY , const char* ObjectName , const char* Tag);
	void CircleDataSet(float Radius , float CenterX , float CenterY , const char* ObjectName , const char* Tag);

	//�R�s�[
	bool CopyBodyData(SquareData& Decision   , const char* ObjectName);//�y�{�́z�̃R�s�[
	bool CopyBodysData(SquareData& Decision  , const char* Tag        , int Count);//�y�^�O���t���������̖{�́z�̃R�s�[
	bool CopyEmptyData(SquareData& Decision  , const char* ObjectName , SquareDirection Direction);//�y��z�̃R�s�[
	bool CopyEmptysData(SquareData& Decision , const char* Tag        , SquareDirection Direction , int Count);//�y�^�O���t���������̋�z�̃R�s�[

	//���W�X�V
	void BodySetPosition(float PositionX , float PositionY , const char* ObjectName);

	//�Փ˔���
	bool EmptyAndEmptyCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2 , SquareDirection Direction2);//�y�󓯎m�z�̏Փ�
	bool BodyAndBodyCollision(const char* ObjectName1   , const char* ObjectName2);//�y�{�̓��m�z�̏Փ�

	bool EmptyAndBodyCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* ObjectName2);//�y��z�Ɓy�{�́z�̏Փ�

	bool EmptyAndBodysCollision(const char* ObjectName1  , SquareDirection Direction1 , const char* Tag2);//�y��z�Ɓy�^�O���t���������̖{�́z�̏Փ�
	bool EmptyAndEmptysCollision(const char* ObjectName1 , SquareDirection Direction1 , const char* Tag2 , SquareDirection Direction2);//�y��z�Ɓy�^�O���t���������̋�z�̏Փ�

	bool BodyAndBodysCollision(const char* ObjectName1  , const char* Tag2);//�y�{�́z�Ɓy�^�O���t���������̖{�́z�̏Փ�
	bool BodyAndEmptysCollision(const char* ObjectName1 , const char* Tag2 , SquareDirection Direction1);//�y�{�́z�Ɓy�^�O���t���������̋�z�̏Փ�
private:
	void BodyInSideDataSet(int Count);
	void BodyUpSetPosition(int Count);
	void BodyRightSetPosition(int Count);
	void BodyDownSetPosition(int Count);
	void BodyLeftSetPosition(int Count);
private:
	SquareData Square[256][5];
	CircleData Circle[256];
	float EmptyWidth = 15.0f;
	float InitValue  = 50000.0f;
};
