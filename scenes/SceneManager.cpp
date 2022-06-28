

SceneManager::SceneManager() {
	view = new QGraphicsView();
	change_scene(init_scene);
	view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	view -> show();
}
SceneManager::~SceneManager() {
	delete view;
}
SceneManager::change_scene(std::string scene_name) {
	scenes[scene_name]->enter();
	view->setScene(scenes[scene_name]);
}
SceneManager::QGraphicsView* getView() {
	return view;
}