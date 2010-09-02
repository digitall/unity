#ifndef _UNITY_H
#define _UNITY_H

#include "engines/engine.h"
#include "common/random.h"

#include "data.h"

namespace Unity {

class Graphics;
class Sound;
class SpritePlayer;
class Object;
class Trigger;

class UnityEngine : public Engine {
public:
	UnityEngine(class OSystem *syst);
	~UnityEngine();

	Common::Error init();
	Common::Error run();

	Object *objectAt(unsigned int x, unsigned int y);

	Common::RandomSource _rnd;

	UnityData data;

	Sound *_snd;

	bool on_bridge;
	Common::String status_text;

	bool in_dialog;
	Common::String dialog_text;
	void setSpeaker(objectID s);

	Conversation *current_conversation;

	// TODO: horrible hack
	Common::Array<unsigned int> dialog_choice_responses;
	Common::Array<unsigned int> dialog_choice_states;
	unsigned int next_situation, next_state;

	void runDialogChoice();
	void runDialog();

protected:
	Graphics *_gfx;

	objectID speaker;
	SpritePlayer *icon;

	void openLocation(unsigned int world, unsigned int screen);

	void checkEvents();
	void handleBridgeMouseMove(unsigned int x, unsigned int y);
	void handleAwayTeamMouseMove(unsigned int x, unsigned int y);
	void handleBridgeMouseClick(unsigned int x, unsigned int y);
	void handleAwayTeamMouseClick(unsigned int x, unsigned int y);

	void drawObjects();
	void processTriggers();

	void startupScreen();
	void startBridge();
	void startAwayTeam(unsigned int world, unsigned int screen);

	void drawDialogWindow();
	void drawAwayTeamUI();
	void drawBridgeUI();

	void handleLook(Object *obj);
};

} // Unity

#endif

