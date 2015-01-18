#ifndef LC_PROFILE_H
#define LC_PROFILE_H

enum LC_PROFILE_KEY
{
	// Settings.
	LC_PROFILE_FIXED_AXES,
	LC_PROFILE_LINE_WIDTH,
	LC_PROFILE_LIGHTING_MODE,
	LC_PROFILE_DRAW_AXES,
	LC_PROFILE_DRAW_EDGE_LINES,
	LC_PROFILE_GRID_STUDS,
	LC_PROFILE_GRID_STUD_COLOR,
	LC_PROFILE_GRID_LINES,
	LC_PROFILE_GRID_LINE_SPACING,
	LC_PROFILE_GRID_LINE_COLOR,
	LC_PROFILE_ANTIALIASING_SAMPLES,

	LC_PROFILE_CHECK_UPDATES,
	LC_PROFILE_PROJECTS_PATH,
	LC_PROFILE_PARTS_LIBRARY,
	LC_PROFILE_SHORTCUTS,
	LC_PROFILE_CATEGORIES,
	LC_PROFILE_RECENT_FILE1,
	LC_PROFILE_RECENT_FILE2,
	LC_PROFILE_RECENT_FILE3,
	LC_PROFILE_RECENT_FILE4,
	LC_PROFILE_AUTOSAVE_INTERVAL,
	LC_PROFILE_MOUSE_SENSITIVITY,
	LC_PROFILE_IMAGE_WIDTH,
	LC_PROFILE_IMAGE_HEIGHT,
	LC_PROFILE_IMAGE_EXTENSION,
	LC_PROFILE_PRINT_ROWS,
	LC_PROFILE_PRINT_COLUMNS,

	// Defaults for new projects.
	LC_PROFILE_DEFAULT_AUTHOR_NAME,
	LC_PROFILE_DEFAULT_FLOOR_COLOR,
	LC_PROFILE_DEFAULT_FLOOR_TEXTURE,
	LC_PROFILE_DEFAULT_FOG_ENABLED,
	LC_PROFILE_DEFAULT_FOG_DENSITY,
	LC_PROFILE_DEFAULT_FOG_COLOR,
	LC_PROFILE_DEFAULT_AMBIENT_COLOR,
	LC_PROFILE_DEFAULT_BACKGROUND_TYPE,
	LC_PROFILE_DEFAULT_BACKGROUND_COLOR,
	LC_PROFILE_DEFAULT_GRADIENT_COLOR1,
	LC_PROFILE_DEFAULT_GRADIENT_COLOR2,
	LC_PROFILE_DEFAULT_BACKGROUND_TEXTURE,
	LC_PROFILE_DEFAULT_BACKGROUND_TILE,

	// Exporters.
	LC_PROFILE_HTML_OPTIONS,
	LC_PROFILE_HTML_IMAGE_OPTIONS,
	LC_PROFILE_HTML_IMAGE_WIDTH,
	LC_PROFILE_HTML_IMAGE_HEIGHT,
	LC_PROFILE_HTML_PARTS_COLOR,
	LC_PROFILE_HTML_PARTS_WIDTH,
	LC_PROFILE_HTML_PARTS_HEIGHT,
	LC_PROFILE_POVRAY_PATH,
	LC_PROFILE_POVRAY_LGEO_PATH,
	LC_PROFILE_POVRAY_RENDER,

	LC_NUM_PROFILE_KEYS
};

enum LC_PROFILE_ENTRY_TYPE
{
	LC_PROFILE_ENTRY_INT,
	LC_PROFILE_ENTRY_FLOAT,
	LC_PROFILE_ENTRY_STRING,
	LC_PROFILE_ENTRY_BUFFER
};

class lcProfileEntry
{
public:
	lcProfileEntry(const char* Section, const char* Key, int DefaultValue);
	lcProfileEntry(const char* Section, const char* Key, unsigned int DefaultValue);
	lcProfileEntry(const char* Section, const char* Key, float DefaultValue);
	lcProfileEntry(const char* Section, const char* Key, const char* DefaultValue);
	lcProfileEntry(const char* Section, const char* Key);

	LC_PROFILE_ENTRY_TYPE mType;

	const char* mSection;
	const char* mKey;

	union
	{
		int IntValue;
		float FloatValue;
		const char* StringValue;
	} mDefault;
};

extern lcProfileEntry gProfileEntries[LC_NUM_PROFILE_KEYS];

void lcRemoveProfileKey(LC_PROFILE_KEY Key);

int lcGetProfileInt(LC_PROFILE_KEY Key);
float lcGetProfileFloat(LC_PROFILE_KEY Key);
const char* lcGetProfileString(LC_PROFILE_KEY Key);
void lcGetProfileBuffer(LC_PROFILE_KEY Key, lcMemFile& Buffer);

void lcSetProfileInt(LC_PROFILE_KEY Key, int Value);
void lcSetProfileFloat(LC_PROFILE_KEY Key, float Value);
void lcSetProfileString(LC_PROFILE_KEY Key, const char* Value); // todo: qstring
void lcSetProfileString(LC_PROFILE_KEY Key, const QString& Value);
void lcSetProfileBuffer(LC_PROFILE_KEY Key, const lcMemFile& Buffer);

#endif // LC_PROFILE_H
