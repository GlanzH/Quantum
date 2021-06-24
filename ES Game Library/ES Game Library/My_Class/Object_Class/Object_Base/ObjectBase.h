#include"../../../ESGLib.h"
#include"../../DATE/Map_Date/MapDate.h"

class Object;


struct MODEL_STATE
{
public:
	Vector3 p_model_position_revision = Vector3(0.0f, 0.0f, 0.0f);
	Vector3 p_hitbox_position_revision = Vector3(0.0f, 0.0f, 0.0f);

	char    tags = '?';

private:
};
enum ATTACK_TYPE { DAMEGE, ITEM, GAMEOVER, ITEMBROCK, END };

struct ATTACK_PARAMETERS
{
public:
	//�^����_���[�W��
	float _AddDamege = 0.1f;
	//����
	ATTACK_TYPE _Type;
private:
};
class Object
{
public:
	Object() ;
	~Object() {};
	void Init() {};
	void Update() {};
	//�`��
     void Draw2D() {};
     void Draw3D() ;
     void DrawAlpha3D() {};
     void DrawEnd() {};
protected:
	ATTACK_PARAMETERS attack_parameters;
	MODEL_STATE   model_parameters;
	//�f�[�^
	std::unique_ptr<MapData> _mapdata;
};

